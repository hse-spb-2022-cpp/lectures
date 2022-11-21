#include <boost/config.hpp>
#include <iostream>
#include "abstract_plugin.h"

namespace plugin_sum {
class plugin_sum : public plugins_demo::abstract_plugin {
public:
    plugin_sum() {
        std::cout << "Constructing plugin_sum\n";
    }

    const std::string &name() const override {
        static std::string name = "sum";
        return name;
    }

    float calculate(float x, float y) override {
        return x + y;
    }

    ~plugin_sum() {
        std::cout << "Destructing plugin_sum\n";
    }
};

extern "C" BOOST_SYMBOL_EXPORT plugin_sum plugin;
plugin_sum plugin;
}  // namespace plugin_sum
