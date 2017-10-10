#pragma once

#include <fc/container/flat.hpp>
#include <calibrae/protocol/operations.hpp>
#include <calibrae/protocol/transaction.hpp>
#include <calibrae/chain/steem_object_types.hpp>

#include <fc/string.hpp>

namespace steemit { namespace app {

using namespace fc;

void operation_get_impacted_accounts(
   const steemit::protocol::operation& op,
   fc::flat_set<protocol::account_name_type>& result );

void transaction_get_impacted_accounts(
   const steemit::protocol::transaction& tx,
   fc::flat_set<protocol::account_name_type>& result
   );

} } // steemit::app
