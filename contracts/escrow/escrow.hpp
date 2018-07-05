#pragma once

#include <eosiolib/asset.hpp>
#include <eosiolib/eosio.hpp>
#include "../eosio.token/eosio.token.hpp"

namespace eosio
{
class escrow : public contract
{
      public:
        escrow(account_name self) : contract(self) {}

        /// @abi action
        void eshello(account_name user);

        /// @abi action
        void esrelease(account_name agent,
                       account_name to,
                       asset quantity);

        /// @abi action
        void estransfer(account_name from,
                        account_name agent,
                        asset quantity);

      private:
};
} // namespace eosio
