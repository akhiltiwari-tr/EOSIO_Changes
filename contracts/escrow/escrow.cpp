#include "escrow.hpp"
#include <vector>
#include <string>

using std::vector;

namespace eosio
{

void escrow::eshello(account_name user)
{
        print("Hello!! from escrow:: ", name{user});
}

void escrow::esrelease(account_name agent,
                       account_name to,
                       asset quantity)
{
        print("Releasing funds from the escrow agent \n");
        eosio::action(
            eosio::permission_level{agent, N(active)}, // --> this works for escrow...
            //     vector<eosio::permission_level>(),
            N(eosio.token), N(transfer),
            std::make_tuple(agent, to, quantity, std::string("escrow release")))
            .send();
}

void escrow::estransfer(account_name from,
                        account_name agent,
                        asset quantity)
{
        print("Transfering funds to the escrow agent \n");
        eosio::action(
            eosio::permission_level{from, N(active)},
            //     vector<eosio::permission_level>(),
            N(eosio.token), N(transfer),
            std::make_tuple(from, agent, quantity, std::string("escrow transfer")))
            .send();
}

EOSIO_ABI(escrow, (eshello)(esrelease)(estransfer));
} // namespace eosio
