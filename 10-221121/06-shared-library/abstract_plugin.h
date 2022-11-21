#ifndef PLUGIN_API_H_
#define PLUGIN_API_H_

#include <boost/config.hpp>
#include <string>

namespace plugins_demo {
class BOOST_SYMBOL_VISIBLE abstract_plugin {
public:
    virtual const std::string &name() const = 0;
    virtual float calculate(float x, float y) = 0;
    virtual ~abstract_plugin() = default;
};
}  // namespace plugins_demo

#endif  // PLUGIN_API_H_
