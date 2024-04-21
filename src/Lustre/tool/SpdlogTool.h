//
// Created by jack on 1/19/24.
//

#ifndef QL2C_SPDLOGTOOL_H
#define QL2C_SPDLOGTOOL_H

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
class SpdlogTool {
    /**
     * 设置spdlog的两个静态控制台输出流logOut(标准输出)和logErr(标准错误输出)
     * 此处只留下标准错误输出流，标准输出留给返回转换后的l2c语法输出
     * 使用方式：
     *      SpdlogTool::logErr->warn("标准错误输出");
     *      SpdlogTool::logErr->error("Error");
     *
     *      SpdlogTool::logOut->info("标准输出输出");
     */

public:
    // create a color multi-threaded logger
//    static std::shared_ptr<spdlog::logger> logOut;

    static std::shared_ptr<spdlog::logger> logErr;

};


#endif //QL2C_SPDLOGTOOL_H
