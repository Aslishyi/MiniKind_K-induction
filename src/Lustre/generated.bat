set "CLASSPATH=.;.\antlr-4.13.1-complete.jar;%CLASSPATH%"
java -Xmx500M -cp "antlr-4.9.2-complete.jar;%CLASSPATH%" org.antlr.v4.Tool -Dlanguage=Cpp -listener -visitor Lustre.g4 -o generated
pause