//
// Created by 李奕星 on 2024/4/12.
//

#include <boost/algorithm/string/trim.hpp>
#include <boost/algorithm/string/find.hpp>
#include "StringTool.h"

std::vector<std::string> StringTool::StrSplitting(std::string str, const std::string& dstr) {
    std::vector<std::string> res;
    boost::split(res, str, boost::is_any_of(dstr));
    StringVectorTool::trimStrings(res);
    return res;
}

bool StringTool::StrCheck(const std::string& str, const std::string& substr) {
    if(str.find(substr) == std::string::npos)
        return false;
    else
        return true;
}

std::string StringTool::get_substring_between(const std::string &str, const std::string &x, const std::string &y) {
    std::size_t start_pos = str.find(x);
    if(start_pos == std::string::npos)
        return ""; // x not found in str

    start_pos += x.length(); // Move past x
    std::size_t end_pos = str.find(y, start_pos);
    if(end_pos == std::string::npos)
        return ""; // y not found after x in str
    std::string tstr = str.substr(start_pos, end_pos - start_pos);
    boost::trim(tstr);
    return tstr;
}

std::string StringTool::get_substring_to(const std::string &x, const std::string &y) {
    std::string result;
    std::string::size_type pos = boost::algorithm::find_first(x, y).begin() - x.begin();
    if (pos != std::string::npos)
        result = x.substr(0, pos);
    else
        result = "";
    boost::trim(result);
    return result;
}

std::string StringTool::get_substring_from(const std::string &x, const std::string &y) {
    std::string result;
    std::string::size_type pos = boost::algorithm::find_first(x, y).begin() - x.begin();
    if (pos != std::string::npos)
        result = x.substr(pos + y.size());
    else
        result = "";
    boost::trim(result);
    return result;
}



