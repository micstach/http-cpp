// Copyright 2014 by Konstantin (Kosta) Baumann
//
// Distributed under the MIT license (See accompanying file LICENSE.txt)
//

#pragma once

#include "utils.hpp"

#include <functional>

namespace cute {

    struct test {
        std::string const name;
        std::set<std::string> const tags;
        std::function<void()> const test_case;
        std::string const file;
        int const line;

        inline test(std::string file_, int line_, std::string name_, std::function<void()> test_case_) :
            name(std::move(name_)), test_case(std::move(test_case_)), file(std::move(file_)), line(std::move(line_))
        { }
        inline test(std::string file_, int line_, std::string name_, std::string const& tags_, std::function<void()> test_case_) :
            name(std::move(name_)), tags(detail::parse_tags(tags_)), test_case(std::move(test_case_)), file(std::move(file_)), line(std::move(line_))
        { }
    };

} // namespace cute
