#include <calibrae/witness/witness_operations.hpp>

#include <calibrae/protocol/operation_util_impl.hpp>

namespace calibrae { namespace witness {

void enable_content_editing_operation::validate()const
{
   chain::validate_account_name( account );
}

} } // calibrae::witness

DEFINE_OPERATION_TYPE( calibrae::witness::witness_plugin_operation )
