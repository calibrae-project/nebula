#pragma once

#include <calibrae/chain/evaluator.hpp>

#include <calibrae/private_message/private_message_operations.hpp>
#include <calibrae/private_message/private_message_plugin.hpp>

namespace calibrae { namespace private_message {

DEFINE_PLUGIN_EVALUATOR( private_message_plugin, calibrae::private_message::private_message_plugin_operation, private_message )

} }
