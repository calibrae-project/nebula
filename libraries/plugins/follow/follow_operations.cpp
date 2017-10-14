#include <calibrae/follow/follow_operations.hpp>

#include <calibrae/protocol/operation_util_impl.hpp>

namespace calibrae { namespace follow {

void follow_operation::validate()const
{
   FC_ASSERT( follower != following, "You cannot follow yourself" );
}

void reblog_operation::validate()const
{
   FC_ASSERT( account != author, "You cannot reblog your own content" );
}

} } //calibrae::follow

DEFINE_OPERATION_TYPE( calibrae::follow::follow_plugin_operation )
