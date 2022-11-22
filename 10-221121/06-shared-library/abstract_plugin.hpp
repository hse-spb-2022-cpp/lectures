#ifndef ABSTRACT_PLUGIN_HPP_
#define ABSTRACT_PLUGIN_HPP_

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

#endif  // ABSTRACT_PLUGIN_HPP_
