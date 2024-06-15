/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobeshota <tobeshota@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:19:58 by tobeshota         #+#    #+#             */
/*   Updated: 2024/06/15 12:34:00 by tobeshota        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#define RULED_LINE " ────────────────────"

static void put_line(void)
{
  static int index;
  std::cout << "- " << index++ << RULED_LINE << std::endl;
}

/*
void free_instance(ClapTrap *p)
{
  delete p;
}

int main(void)
{
  FragTrap *ft = new FragTrap("ft");
  free_instance(ft);
  put_line();
}
*/

/* 仮想継承とvirtualキーワード

@仮想継承とは？
仮想継承（virtual inheritance）は、多重継承時にベースクラスのデータメンバーやメンバー関数が複数回継承される問題を防ぐための仕組みです。
多重継承を行う場合、同じ基底クラスが複数回継承されることがあります。
このとき、基底クラスのメンバーが複数存在することになるため、どのメンバーを参照するのかが不明確になります。
仮想継承を使用すると、派生クラスに基底クラスのデータメンバーやメンバー関数が一度だけ存在するようになります。

@virtual キーワード
virtualキーワードは、仮想継承を指定するために使います。
具体的には、基底クラスを仮想継承する場合に、クラス宣言でvirtualキーワードを使用します。

// 基底クラス
class Base {
public:
    int value;
    Base() : value(0) {}
};

// 中間クラスA
class DerivedA : virtual public Base {
public:
    DerivedA() {}
};

// 中間クラスB
class DerivedB : virtual public Base {
public:
    DerivedB() {}
};

// 最終クラス
class Final : public DerivedA, public DerivedB {
public:
    Final() {}
};


上記の例では、BaseクラスはDerivedAとDerivedBによって仮想継承されています。
このため、FinalクラスにはBaseクラスのメンバーvalueが一度だけ存在します。

*/

int main() {
  put_line();
  // (constructor)ClapTrap Diamond_clap_name has been created!
  // (constructor)FragTrap Default constructor called
  // (constructor)ScavTrap Default constructor called
  // (constructor)DiamondTrap Diamond has been created!
  DiamondTrap d1("Diamond");
  put_line();

  // ScavTrap Diamond_clap_name attacks target, causing 20 points of damage!
  d1.attack("target");
  put_line();

  // ClapTrap Diamond_clap_name takes 20 points of damage!
  d1.takeDamage(20);
  put_line();

  // ClapTrap Diamond_clap_name is repaired for 10 points!
  d1.beRepaired(10);
  put_line();

  // I am Diamond and my ClapTrap name is Diamond_clap_name
  // DiamondTrap Diamond is now in Gate keeper mode!
  d1.whoAmI();
  put_line();

  // (destructor)DiamondTrap Diamond has been destroyed!
  // (destructor)ScavTrap Diamond_clap_name has been destroyed!
  // (destructor)FragTrap Diamond_clap_name has been destroyed!
  // (destructor)ClapTrap Diamond_clap_name has been destroyed!
  return 0;
}


#ifdef DEBUG

__attribute__((destructor)) static void destructor() {
  system("leaks -q a.out");
}

#endif
