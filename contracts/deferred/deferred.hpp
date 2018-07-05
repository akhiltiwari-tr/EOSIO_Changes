#pragma once
#include <eosiolib/eosio.hpp>
#include "../escrow/escrow.hpp"
#include <vector>

using eosio::contract;
using std::vector;

class deferred : public eosio::contract
{
public:
  deferred(account_name self) : contract(self) {}

  // @abi action
  void defhello(account_name account);

private:
  // private members

}; // class deferred
