#include "deferred.hpp"

void deferred::defhello(account_name account)
{
    require_auth(account);

    // ==> LOCALLY PRINTS TO CONSOLE <==
    // eosio::print("This is defhello, ", eosio::name{account});

    // eosio::print(" N(active)", N(active));
    // eosio::print(" N(active)", active);
    // eosio::print(" N(\"active\")", N("active"));

    // INLINE_ACTION_SENDER(eosio::escrow, escrow::eshello(N(escrow), {account, N(active)}, {account, N(account)}));

    // ==> account authorization error on pushing transaction <==
    eosio::action(
        // eosio::permission_level{account, N(active)},
        vector<eosio::permission_level>(), // how come this works
        N(escrow), N(eshello),
        account)
        .send();

    // ==> This will not allow the contract to be published. <==
    // eosio::escrow esc_obj(account);
    // esc_obj.eshello(account);
}
EOSIO_ABI(deferred, (defhello));
