#pragma once
#include <calibrae/protocol/block_header.hpp>
#include <calibrae/protocol/transaction.hpp>

namespace calibrae { namespace protocol {

   struct signed_block : public signed_block_header
   {
      checksum_type calculate_merkle_root()const;
      vector<signed_transaction> transactions;
   };

} } // calibrae::protocol

FC_REFLECT_DERIVED( calibrae::protocol::signed_block, (calibrae::protocol::signed_block_header), (transactions) )
