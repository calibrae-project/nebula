
#pragma once

#include <memory>
#include <string>
#include <vector>

namespace calibrae { namespace app {

class abstract_plugin;
class application;

} }

namespace calibrae { namespace plugin {

void initialize_plugin_factories();
std::shared_ptr< calibrae::app::abstract_plugin > create_plugin( const std::string& name, calibrae::app::application* app );
std::vector< std::string > get_available_plugins();

} }
