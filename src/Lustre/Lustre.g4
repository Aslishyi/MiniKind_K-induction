grammar Lustre;

//语法分析器规则以小写字母开头
//词法分析器规则以大写字母开头

/*1、程序定义
  program ::= {{ decls }}
  decls ::= type_block                   //类型块
  	| const_block                     //常量块
  	| user_op_decl                    //节点定义
*/
program: include|(decls|pack_list)+;

//package和model
include: 'include' STRING ';';
pack_list: one_park+;
one_park: model_decl|pack_decl|pack_eq;
pack_decl: 'package' ID  uses provides  'body' decls 'end';
uses: 'uses' ID (',' ID)* ';';
pack_eq: 'package' ID  ('='|'is') ID  ;

provides: 'provides' provide ';' ( provide ';')*;
provide: const_block
        | type_block
        | user_op_provide
        ;

model_decl: 'model' ID  uses 'needs' user_op_provide  'body' decls 'end';

user_op_provide : op_kind ID                                       //节点定义
                params                         //输入参数列表
                'returns'
                params                         //输出参数列表
                ;

//程序定义
//Add Kind2 Comment
decls: type_block                               # decls_type
     | const_block                              # decls_const
     | import_op_decl                           # decls_import_op
     | user_op_decl                             # decls_user_op
     | external_contract                        # decls_contract_node
     ;
/*
mode <id> (
[require <expr> ;]*
[ensure <expr> ;]*
) ;
::<scope>::<mode_id>

var <id> : <type> = <expr> ;
assume <expr> ;
guarantee <expr> ;
*/


/*
2、类型定义
type_block ::= type {{ type_decl；}}
type_decl ::= ID [[ = type_def ]]
type_def ::= type_expr
		| enum { ID {{ , ID }}}
type_expr (->type)::= bool                    //布尔类型
		| char                       //字符类型
        | short                      //16位带符号整型
        | ushort                     //16位无符号整型
        | int                        //32位带符号整型
        | uint                       //32位无符号整型
		| float                      //32位浮点
        | real                       //64位浮点
		| typevar                    //类型名
		| { field_decl {{, field_decl}} }  //结构体类型
		| type_expr  ^  const_expr    //数组类型
field_decl ::= ID : type_expr
typevar ::= ID
类型定义需要注意类型名定义和数组定义。类型名支持引用其他已经定义好的类型。数组类型的数组长度支持常量表达式，常量表达式必须是可计算可确定的，并且计算结果为整型。下面是类型定义的示例。
type
    struct1 = {label1 : int, label2 :bool};
    struct_type = {label1 : int, label2 : bool^3, label3 : struct1};
    enum_type = enum {a1, a2, a3};

*/
type_block: 'type'  (type_decl ';')* ;
type_decl: ID ('=' type_def)? ;

//type_def:  ID '=' topLevelType ';';
type_def: type                                         # type_def_type
        | 'enum' '{' ID (',' ID)* '}'                  # type_def_enum
        ;

type: 'int'                                              # type_int
    | 'bool'                                             # type_bool
    | 'char'                                             # type_char
    | 'short'                                            # type_short
    | 'ushort'                                           # type_ushort
    | 'uint'                                             # type_uint
    | 'float'                                            # type_float
    | 'real'                                             # type_real
    | ID                                                 # type_id
    | 'struct'?'{' field_decl ((','|';') field_decl)* '}'# type_struct
    | type '^' const_expr                                # type_array
    ;

field_decl: ID ':' type;

/*
3、常量定义
const_block ::= const {{ const_decl; }}					//常量块定义
const_decl ::= ID : type_expr [[= const_expr]]			//常量声明

const_expr ::= ID									//常量ID
		| atom									//基本常量
        | unary_arith_op  const_expr					//常量的一元运算
		| const_expr  bin_arith_op  const_expr 		//常量的二元算术运算
        | const_expr  bin_bool_op  const_expr		//常量的二元布尔运算
        | const_expr  bin_realtion_op  const_expr		//常量的二元比较运算
        | [ const_list ]								//数组常量
        | { const_label_expr {{ , const_label_expr }} }	//结构体常量
const_list ::= [[ const_expr {{, const_expr}} ]]			//数组常量内部定义
const_label_expr ::= ID : const_expr					//结构体常量内部定义
常量表达式主要用在全局常量定义、类型定义中的数组长度定义、高阶运算中的迭代次数、fby中的常数定义和数组运算中。除全局常量定义以外，其他定义中都要求常量表达式必须是可计算可确定的，并且计算结果为整型。
下面是常量定义的示例：
const
arr1 : int ^4 = [1, 2, 3, 4];				//数组常量
stru:struct1 = {label1:len, label2:false};	//结构体常量
len:int = 5;							//整数常量
enu:enum_type = a1;					//枚举常量
c1: int = 2+3;							//int常量表达式
c2: uint = 2u+3u;						//uint常量表达式
c3: short = 2s+3s;					//short常量表达式
c4: ushort = 2us+3us;					//ushort常量表达式
c5: real = 3.4+2.5;					//real常量表达式
c6: float = 7.5f+6.4f;					//float常量表达式
*/
const_block: 'const'  (const_decl ';')* ;
//修改，原：     const_decl:  ID (':' type)? '=' const_expr;
//测试kind2：const x1: int = 1;            const x1: int;          const x1 = 1;         均通过
const_decl:  ID  (':' type)? ('=' const_expr)?;

const_expr:ID                                                       #const_id
          | atom                                                    #const_atom
          | unary_arith_op  const_expr                              #const_unary_arith  //常量的一元运算
          |'(' const_expr ')'                                       #const_paren
          | const_expr  bin_arith_op  const_expr                    #const_bin_arith    //常量的二元算术运算
          | const_expr  bin_bool_op  const_expr                     #const_bin_bool     //常量的二元布尔运算
          | const_expr  bin_relation_op  const_expr                 #const_bin_relation //常量的二元比较运算
          | '[' const_list ']'                                      #const_array        //数组常量
          | '{' const_label_expr  ( ',' const_label_expr)* '}'      #const_struct       //结构体常量
          ;

const_list : ( const_expr (',' const_expr)* )?;                    //数组常量内部定义
const_label_expr : ID ':' const_expr;

/*
4、变量定义
var_decls ::= var_id {{, var_id}} : type_expr [[ when_decl ]]	//变量声明
                                     [[ last_decl ]]
var_id ::= ID 											//变量ID定义
when_decl ::= when clock_expr							//变量时钟声明
clock_expr ::= ID 										//时钟表达式定义
			| not ID
last_decl ::= last = const_expr
变量定义既支持对每个变量单独定义，也支持对类型和时钟相同的变量集中定义。
*/
var_decls : ID (',' ID)* ':' type  when_decl? last_decl?;               //变量声明
when_decl : 'when' clock_expr;                                          //变量时钟声明
clock_expr : ID                                #clock_id                //时钟表达式定义
           | 'not' '('? ID ')'?                #clock_not
           ;
//last关键字
last_decl : 'last' '=' const_expr;


/*5、节点定义
user_op_decl ::= op_kind ID					//节点定义
            params returns params 			//输入参数和输出参数
            op_body 						//节点体
op_kind ::= function						//节点类型分为函数和变量
            | node
params ::= ( [[ var_decls {{ ; var_decls}} ]] )	//参数列表定义
opt_body ::= ；							//空节点.
            | [[ local_block ]]					//局部变量定义可以为空
            let {{ equation ; }} tel [[; ]]

local_block ::= var {{ var_decls ;}}			//局部变量定义
需要注意的是如果节点类型为函数，则节点内部不能包含时态运算。
*/
user_op_decl : op_kind ID  /*static_parameters? */                                   //节点定义
                params 'returns' params ';'?                        //输入参数和输出参数
                op_body                                                 //节点体
                ;
op_kind : 'function'                      #op_kind_funtion                      //节点类型分为函数和变量
        | 'node'                          #op_kind_node
//        | 'unsafe' 'node'                #op_kind_unsafe_node_lv6
//        | 'unsafe' 'function'           #op_kind_unsafe_function_lv6
        ;


//static_parameters:'<<' static_parameter (';' static_parameter)* '>>';     //lv6静态参数列表
//
//static_parameter:'type' ID
//                | 'const' ID ':' type
//                | 'node' ID params 'returns' params
//                | 'function' ID  params 'returns' params
//                | 'unsafe' 'node' ID params 'returns' params
//                | 'unsafe' 'function' ID  params 'returns' params
//                ;

params : '(' ( var_decls ( ';' var_decls)* )? ';'? ')';      //参数列表定义
//Add Kind2 Blocks
op_body : ';'                                                   #op_body_null      //空节点
          | contract?       //kind2契约语法
            local_block?      //局部变量定义可以为空
            'let'
            // let_block ';'
             let_block*
//        (equation | property | assertion | main | realizabilityInputs | ivc)*
            'tel' ';' ?                                         #op_body_ctx
          ;
contract:'(*@contract' kind2_contract_item* '*)'
        |'/*@contract' kind2_contract_item* '*/'
 //       |CONTRACT
        ;
local_block : 'var' (var_decls ';')*;                   //局部变量定义
let_block:
            equation ';'                                      #let_block_equation
//          | call_fun                                        #let_block_call_fun
            | kind2_property                                  #let_block_k2_property
            | kind2_if_block 'fi'                             #let_block_k2_if_block
            | kind2_frame_block                               #let_block_k2_frame_block
            ;
//(*@contract [item]+ *)	/*@contract [item]+ */
//Or can ues kind2_contract_decl to specify
//contract_statement:CONTRACT;
external_contract: 'contract' ID  /*static_parameters? */                                   //节点定义
                    params 'returns' params ';'?                        //输入参数和输出参数
                    contract_body                                                 //节点体
                    ;

contract_body:'let' kind2_contract_item+ 'tel';

kind2_contract_item:
            mode_decl                           # decls_mode
            |kind2_const_item                   # decls_const_ghost_var
            |kind2_var_item                     # decls_ghost_var
            |assume_item                        # decls_assume
            |guarantee_item                     # decls_guarantee
            |import_item                        # decls_imports
            ;

mode_decl: 'mode' ID '(' mode_body ')' ';';
mode_body: (requirement | assurance)+ ;
requirement: 'require' .*? ';';
assurance: 'ensure' .*? ';';

kind2_const_item: ID (':' type)? '=' .*? ';';
kind2_var_item: 'var' ID ':' type '=' .*? ';';
assume_item: 'assume' .*? ';';
guarantee_item: 'guarantee' .*? ';';
import_item: 'import' ID '('( expr',')* expr ')' 'returns' '(' (ID',')* ID ')'';';

kind2_if_block: 'if' simple_expr 'then' (simple_expr';')+ kind2_if_body*;
kind2_if_body:	'elsif' simple_expr 'then' (simple_expr';')+
				|'else' (simple_expr';')+
				;


/*
--%PROPERTY ["<name>"] <bool_expr> ;
check ["<name>"] <bool_expr> ;
--%PROPERTY reachable ["<name>"] <bool_expr> [from <int>] [within <int>];
check reachable ["<name>"] <bool_expr> [from <int>] [within <int>];
check reachable ["<name>"] <bool_expr> at <int>;
--%MAIN ;
*/

kind2_property: MAIN           #kind2_statement_main
            | PROPERTY         #kind2_statement_property
            | CHECK            #kind2_statement_check;
//mainStatement: '--%MAIN' ';';
//propertyStatement: '--%PROPERTY' .*? ';';
//checkStatement: 'check' .*? ';';

/*
frame ( y1, y2, y3 )
    (* Initializations *)
    y1 = 0; y2 = 100; y3 = 5;
    (* Body *)
    let
    y2 = pre counter();
    y3 = counter();
tel
*/
kind2_frame_block: frame_init  frame_body;
frame_init: 'frame' '(' ID (','ID)* ')' (simple_expr ';')*;
frame_body: 'let' (equation ';')* 'tel' ;

/*
6、外部函数定义
user_op_decl ::= function imported ID		//外部函数定义
			params returns params 			//输入参数和输出参数
*/
import_op_decl : 'function' 'imported'  ID                 //外部函数定义
                params 'returns' params                         //输入参数和输出参数
                ;

//import_op_kind : 'function'    'imported'                  #import_op_kind_funtion                      //节点类型分为函数和变量
//        | 'extern' 'node'                          #import_op_kind_node_lv6
//        | 'extern' 'function'                      #import_op_kind_function_lv6
//        | 'unsafe' 'extern' 'node'                #import_op_kind_unsafe_node_lv6
//        | 'unsafe' 'extern' 'function'           #import_op_kind_unsafe_function_lv6
//        ;

/*
7、等式定义
equation ::= lhs = expr			//等式定义
         ｜state_machine return
lhs ::= ( )						//左值定义
	| lhs_id {{, lhs_id}}
lhs_id ::= ID
return ::= returns returns_var
returns_var ::= {{ ID , }} (( ID | .. ))
这里的等式都是简单等式，即不允许时态运算、call运算、高阶运算等互相嵌套使用。
*/

equation : lhs '=' expr               #equation_expr          //等式定义
         | state_machine return       #equation_state_machine
//         | lhs '=' call_fun           #equation_call_fun      //lv6
//         | 'assert' expr              #equation_assert
         ;
//call_fun: lhs '=' fun_id call_fun_static_parameters? '(' expr (',' expr)* ')' | fun_id '(' expr (',' expr)* ')';
//call_fun_static_parameters:'<<' ID (';' ID)* '>>';
//fun_id : ID;

lhs : '(' ')'                                          #lhs_pair              //左值定义
    | '('? ID (',' ID)* ')'?                           #lhs_id_list
    ;
return : 'returns' returns_var;
returns_var : ( ID ',')*   (ID | '..' )?;



/*8、状态机
state_machine ::= automaton [[ ID ]] {{ state_decl }}+   //状态机声明

state_decl ::= [[ initial ]] [[ final ]] state ID             //状态声明
           [[ unless {{ transition ; }}+ ]]           //强迁移列表
           data_def                            //状态内语句
           [[ until {{ transition ; }}               //弱迁移列表

data_def ::= equation ;                              //等式
       |  [[ local_block ]] [[ let {{ equation ; }} tel ]]  //子变量和等式列表
transition ::= if expr resume ID                       //resume切换的状态迁移语句
      ｜ if expr restart ID                        //restart切换的状态迁移语句
*/
state_machine : 'automaton'  ID?   state_decl+;   //状态机声明
state_decl  :  INITIAL?  FINAL? 'state' ID             //状态声明
            ( unless_tran )?           //强迁移列表
            data_def                            //状态内语句
            ( until_tran )?               //弱迁移列表
            ;

data_def : equation                                             #state_machine_data_def_equation    //等式
         | local_block ? ( 'let' ( equation ';' )* 'tel' )?     #state_machine_data_def_local_block    //子变量和等式列表

         ;
//为了在visitor中区分transition到底是强迁移还是弱迁移，所以分开书写
unless_tran : UNLESS ( transition ';' )+;
until_tran : UNTIL ( transition ';' )*;

transition : 'if' expr 'resume' ID                              #state_machine_transition_resume     //resume切换的状态迁移语句
           |'if' expr 'restart' ID                              #state_machine_transition_restart   //restart切换的状态迁移语句
           ;

/*9、表达式定义
  expr ::= simple_expr 		//简单表达式
     ｜last 'ID             //last运算符
  	| tempo_expr			//时态运算表达式
  		| bool_expr			//布尔运算表达式
  	| array_expr			//数组运算表达式
  	| struct_expr			//结构体运算表达式
  	| mixed_constructor		//mix运算表达式
  	| switch_expr 			//条件分支表达式
  	| apply_expr			//prefix和高阶运算表达式。
  注意上面的各种表达式中的子表达式只能是简单表达式。

list ::= [[ simple_expr {{, simple_expr}} ]]					//表达式列表
*/

expr : simple_expr 		            #expr_simple_expr           //简单表达式
    | 'last' '\''ID                 #expr_last_decl             //last运算符
	| tempo_expr			        #expr_tempo_expr            //时态运算表达式
	| bool_expr			            #expr_bool_expr             //布尔运算表达式
	| array_expr			        #expr_array_expr            //数组运算表达式
//	| array_expr expr               #expr_array_expr_expr       //数组运算表达式
	| struct_expr			        #expr_struct_expr           //结构体运算表达式
	| mixed_constructor             #expr_mixed_constructor     //mix运算表达式
	| switch_expr 			        #expr_switch_expr           //条件分支表达式
	| '(' expr ')'                  #expr_paren                 //括号表达式
	| apply_expr			        #expr_apply_expr            //prefix和高阶运算表达式。
	| kind2_expr                    #expr_kind2_expr
	;

list : ( simple_expr (',' simple_expr)* )?;				//表达式列表

/*
= (activate <node_name> every <clock>)(<input_1>, <input_2>, ...)
= (restart n every c)(x1, ..., xn)
(activate (restart n every r) every c)(a1, ..., an)
(activate n every c restart every r)(a1, ..., an)
*/

kind2_expr:activate_expr | restart_expr;
activate_expr: '('activate')' kind2_param
                |'(''activate' '('restart')' 'every' ID ')' kind2_param ;
restart_expr: '('restart')'kind2_param
                | '('activate 'restart' 'every' ID')' kind2_param;
kind2_param: '('(ID|atom) (','(ID|atom))*')';
activate: 'activate' ID 'every' ID ;
restart: 'restart' ID 'every' ID ;
/*时态运算表达式
tempo_expr ::= pre simple_expr 							//pre表达式
            | simple_expr -> simple_expr					//arrow表达式
            | fby (simple_expr;  const_expr;  simple_expr)	//fby表达式
            | simple_expr fby simple_expr				//不带常数的fby表达式
            | simple_expr when clock_expr				//when表达式
            | merge ID (simple_expr)  (simple_expr)		//merge表达式
Kind2: merge( <clock> ; <e_1> ; <e_2> )
*/
tempo_expr  : 'pre' simple_expr 							#tempo_expr_pre         //pre表达式
            | simple_expr '->' tempo_expr				    #tempo_expr_arrow_tempo         //arrow表达式
            | simple_expr '->' simple_expr					#tempo_expr_arrow       //arrow表达式
            | 'fby' '('simple_expr (','simple_expr)* ';'  const_expr  ';'  simple_expr (','simple_expr)*')'     #tempo_expr_fby	//fby表达式
            | simple_expr 'fby' simple_expr				    #tempo_expr_fby_noconst//不带常数的fby表达式
			| simple_expr 'when' clock_expr				    #tempo_expr_when        //when表达式
			| 'merge' ID (simple_expr)  (simple_expr)		#tempo_expr_merge       //merge表达式
			| 'merge' '(' merge_expr (';' merge_expr)* ')'                          #tempo_kind2_merge
			//| 'current' simple_expr                      //lv6 current运算
			;

/*布尔运算
bool_expr ::= #（list）									//bool运算表达式
*/
bool_expr : '#' '('? list ')'?;									//bool运算表达式     //修改，原：  '#'? '('? list ')'?

/*
数组运算
array_expr ::= simple_expr [ INTEGER .. INTEGER ]				//数组分片运算
			| ( simple_expr . {{ index}}+ default simple_expr )	//数组动态投影运算
			| simple_expr ^ const_expr 						//数组初始化运算1
			| [ list ]										//数组初始化运算2
*/
array_expr : simple_expr '[' INTEGER '..' INTEGER ']'				    #array_expr_split       //数组分片运算
			| '(' simple_expr '.' (index)+  'default' simple_expr ')'   #array_expr_dynamic	    //数组动态投影运算
			| simple_expr '^' const_expr 						        #array_expr_and       //数组初始化运算1
//			| type '^' '('? const_expr ')'?
			| '[' list ']' (',' '['list']')*							#array_expr_list		//数组初始化运算2
			//| '(' array_expr ')'								//数组初始化运算3      //在expr中实现过嵌套括号，删除此处
			;

/*结构体运算
  struct_expr ::= {label_expr {{, label_expr}} }					//结构体初始化运算
*/
struct_expr : '{'label_expr ((','|';') label_expr)*'}';					//结构体初始化运算
/*
mix运算
mixed_constructor ::= (ID with {{ label_or_index }}+ = simple_expr) //mix运算
label_expr ::= ID : simple_expr
index ::= [ simple_expr ]
label_or_index ::= . ID
			| index

*/
mixed_constructor : '('ID 'with' (label_or_index )+ '=' simple_expr')'; //mix运算
label_expr : ID ':' simple_expr;
index : '[' simple_expr ']';
label_or_index : '.' ID             #mix_label
			| index                 #mix_index
			;

/*
条件分支运算
swith_expr ::= if simple_expr then simple_expr else simple_expr 	//ifelse运算
| ( case simple_expr of {{ case_expr }}+ )			//case运算
case_expr ::= | pattern : simple_expr
pattern ::= ID
        | CHAR
		| [[-]] INTEGER
		| true
        | false
		| _
*/
switch_expr : 'if' simple_expr 'then' simple_expr 'else' simple_expr 	#switch_expr_ifelse//ifelse运算
           | '(' 'case' simple_expr 'of' ( case_expr )+ ')'			#switch_expr_case//case运算
//           | 'with' simple_expr 'then' simple_expr 'else' simple_expr		//lv6:with运算
           ;

case_expr : '|' pattern ':' simple_expr;
pattern : ID
        | CHAR
		| '-'? INTEGER
		| BOOL      //true | false
		| '_'
		;

/*
高阶运算表达式
apply_expr ::= prefix_operator (list)
        | (iterator  << prefix_operator;  const_expr >>)(list)
		| (mapw  << prefix_operator;  const_expr >> if simple_expr default (list))(list)
		| (mapwi  <<prefix_operator;  const_expr>> if simple_expr default (list))(list)
		| (foldw   << prefix_operator;  const_expr >> if simple_expr)(list)
		| (foldwi  <<prefix_operator;  const_expr>> if simple_expr)(list)

prefix_operator ::= ID
        | prefix_unary_operator		//一元prefix运算符
        | prefix_binary_operator		//二元prefix运算符
		| (make ID)				//make运算
		| (flatten ID)				//flatten运算
prefix_unary_operator ::= +$ | -$ | not$ | short$ | int$ | float$ | real$
prefix_binary_operator ::= $+$ | $-$ | $*$ | $/$ | $mod$ | $div$
                        | $=$ | $<>$ | $<$ | $>$ | $<=$ | $>=$
                        | $and$ | $or$ | $xor$
interator ::= map | fold | mapi | foldi
		| mapfold

*/

apply_expr : prefix_operator '('list')'                                                                         #apply_prefix
//            | iterator  '<<' prefix_operator','  const_expr '>>''('list')'                                     #apply_iterator
            | 'map'  '<<' prefix_operator';'  const_expr '>>''('list')'                                         #apply_map
            | 'fold'  '<<' prefix_operator';'  const_expr '>>''('list')'                                        #apply_fold
            | 'mapi'  '<<' prefix_operator';'  const_expr '>>''('list')'                                        #apply_mapi
            | 'foldi'  '<<' prefix_operator';'  const_expr '>>''('list')'                                       #apply_foldi
            | 'mapfold'  '<<' prefix_operator';'  const_expr '>>''('list')'                                     #apply_mapfold
//            | 'boolred'  '<<' const_expr','  const_expr (','const_expr)? '>>' '('list')'                        #apply_boolred
            | 'mapw'  '<<' prefix_operator';' const_expr '>>''if' simple_expr 'default' '('list')''('list')'    #apply_mapw
            | 'mapwi'  '<<'prefix_operator';'  const_expr'>>' 'if' simple_expr 'default' '('list')''('list')'   #apply_mapwi
            | 'foldw'   '<<' prefix_operator';'  const_expr '>>' 'if' simple_expr'('list')'                     #apply_foldw
            | 'foldwi'  '<<'prefix_operator';'  const_expr'>>' 'if' simple_expr'('list')'                       #apply_foldwi
            ;

prefix_operator : ID                              #perfix_ID
                | prefix_unary_operator		      #prefix_unary //一元prefix运算符
                | prefix_binary_operator		  #prefix_binary//二元prefix运算符
//                | predef_operator_lv6             #predef_operator
		        | '(' 'make' ID ')'				      #perfix_make      //make运算        //修改
		        | '(' 'flatten' ID ')'				  #perfix_flatten      //flatten运算        //修改
		        ;
prefix_unary_operator : '+$' | '-$' | 'not$' | 'short$' | 'int$' | 'float$' | 'real$';
//                        |'not'|'fby'|'pre'|'current'|'->'|'and'|'or'|'xor'
//                        | '=>'|'='|'<>'|'<'|'<='|'>'|'>='|'div'|'mod'|'-'|'+'|'*'|'/'|'if';
prefix_binary_operator : '$+$' | '$-$' | '$*$' | '$/$' | '$mod$' | '$div$'
                        | '$=$' | '$<>$' | '$<$' | '$>$' | '$<=$' | '$>=$'
 		                | '$and$' | '$or$' | '$xor$'
 		                ;
//下面5行改到上一级的 apply_expr 中实现
//iterator : 'map'                                    #iterator_map
//        | 'fold'                                    #iterator_fold
//        | 'mapi'                                    #iterator_mapi
//        | 'foldi'                                   #iterator_foldi
//        | 'mapfold'                                 #iterator_mapfold

//        | 'red'                                     #iterator_red
//        | 'fill'                                    #iterator_fill
//        | 'fillred'                                 #iterator_fillred
//        | 'boolred'                                 #iterator_boolred
//        ;
/*
simple_expr ::= ID									//变量或常量id
		| atom									//基本常量表达式
		| simple_expr [ const_expr ]					//数组取子元素运算
        | simple_expr . ID							//结构体取子元素运算
        | unary_arith_op  simple_expr				//一元运算
		| simple_expr  bin_arith_op  simple_expr		//二元算术运算
        | simple_expr  bin_bool_op  simple_expr		//二元布尔运算
        | simple_expr  bin_realtion_op  simple_expr	//二元比较运算
		| (type_expr  simple_expr)					//强制类型转换
unary_arith_op  ::= - | + | not						//一元运算符
bin_arith_op ::= + | - | * | / | mod | div 					//二元算术运算符
bin_relation_op ::= =| <> | < | > | <= | >= 				//二元比较运算符
bin_bool_op ::= and | or | xor 						//二元布尔运算符

*/
simple_expr : ID                                                #simple_expr_id
		| atom                                                  #simple_expr_atom       //基本常量表达式
		|'(' simple_expr (',' simple_expr)* ')'                 #simple_expr_paren
		| simple_expr '[' const_expr ']'                        #simple_expr_array      //数组取子元素运算
        | simple_expr '.' ID                                    #simple_expr_struct			//结构体取子元素运算
        | unary_arith_op  simple_expr                           #simple_expr_unary_arith        	//一元运算
		| simple_expr  bin_arith_op  simple_expr                #simple_expr_bin_arith        	//二元算术运算
        | simple_expr  bin_bool_op  simple_expr                 #simple_expr_bin_bool			//二元布尔运算
        | simple_expr  bin_relation_op  simple_expr             #simple_expr_bin_relation        	//二元比较运算
		| type  simple_expr                                     #simple_expr_type        	//强制类型转换，修改，删掉了括号，expr中有对应括号实现
            //数组初始化运算
        | bin_relation_op kind2_expr                            #simple_kind2_expr
//	    | type '^' '('? const_expr ')'?

//        |  type
		;
unary_arith_op  : '-'           #unary_arith_op_sub
                | '+'           #unary_arith_op_add
                | 'not'			#unary_arith_op_not			//一元运算符
                ;

bin_arith_op : '+'                          #bin_arith_op_add
             | '-'                          #bin_arith_op_sub
             | '*'                          #bin_arith_op_mul
             | '/'                          #bin_arith_op_divided
             | 'mod'                        #bin_arith_op_mod
             | 'div'                        #bin_arith_op_div         //整除运算
             ; 					//二元算术运算符
bin_relation_op : '=' | '<>' | '<' | '>' | '<=' | '>='; 				//二元比较运算符
bin_bool_op : 'and' | 'or' | 'xor'; 						//二元布尔运算符

/*atom ::= true				//bool常量true
      	| false			//bool常量false
  		| CHAR			//字符常量
  		| INTEGER		//32位整型int常量
        | UINT			//无符号32位整型常量
  		| FLOAT			//32位浮点常量
        | REAL			//64位浮点常量
        | USHORT		//无符号16位整型常量
        | SHORT			//带符号16位整型常量
*/
atom    : BOOL        #atom_BOOL          //bool常量      //true|false
        | CHAR        #atom_CHAR          //字符常量
        | INTEGER     #atom_INTEGER      //32位整型int常量
        | UINT        #atom_UINT          //无符号32位整型常量
        | FLOAT       #atom_FLOAT          //32位浮点常量
//        | FLOATLV6    #atom_FLOATLV6          //32位浮点常量
        | REAL        #atom_REAL          //64位浮点常量
        | USHORT      #atom_USHORT          //无符号16位整型常量
        | SHORT       #atom_SHORT          //带符号16位整型常量
        ;

//Kind2_merge
merge_expr: ID
            |tempo_expr
            |kind2_expr
            ;

//状态机的词法符号,得放在上面，不然会被识别为string
INITIAL: 'initial';
FINAL: 'final';
UNLESS: 'unless';
UNTIL: 'until';

//类型定义
BOOL: 'true' | 'false';
INTEGER: [0-9]+;
UINT: INTEGER 'u';
REAL: INTEGER '.' INTEGER;
CHAR: '\'' . '\'';
FLOAT: [0-9]+ '.' [0-9]+ 'f';
//FLOATLV6: [0-9]+ '.' [0-9]* ;
USHORT: INTEGER 'us';
SHORT: INTEGER 's';

// ~ is used internally. Users should not use it.
ID: [a-zA-Z_~!][a-zA-Z_0-9~!]*; //匹配标识符

//CONTRACT: '(*@contract' .*? '*)' | '/*@contract' .*? '*/';
SL_COMMENT: '--' ~[%\r\n]* -> skip;
ML_COMMENT: (('/*'~[@].*?'*/') | '(''*'~[@].*?'*'')') -> skip;
PRAGMA: '%' .*? ('\r'? '\n' | EOF) -> skip;
STRING: '"' (~[ %\r\n])* '"';

MAIN : '--%MAIN';
PROPERTY: '--%PROPERTY' ~[;\r\n]*;
CHECK: 'check' ~[;\r\n]*;



WS: [ \t\n\r\f]+ -> skip;   //丢弃空白字符
ERROR: .;

