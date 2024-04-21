//
// Created by jack on 1/19/24.
//

#include "SpdlogTool.h"
//std::shared_ptr<spdlog::logger> SpdlogTool::logOut = spdlog::stdout_color_mt("stdout");
std::shared_ptr<spdlog::logger> SpdlogTool::logErr = spdlog::stderr_color_mt("stderr");
