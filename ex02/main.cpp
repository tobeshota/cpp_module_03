/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:19:58 by tobeshota         #+#    #+#             */
/*   Updated: 2024/06/14 19:24:40 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
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
/*
コンストラクタチェーンとは、C++において派生クラスのオブジェクトが生成される際に、
基底クラス（親クラス）のコンストラクタがまず呼び出され、
その後に派生クラス（子クラス）のコンストラクタが呼び出されるというプロセスを指します。
この順序は、クラスの継承階層を上から下に向かって進みます。
*/
int main() {
  put_line();
  // (constructor)ClapTrap FT_1 has been created!
  // (constructor)FragTrap FT_1 has been created!
  FragTrap s1("FT_1");

  put_line();
  // ClapTrap FT_1 attacks target1, causing 30 points of damage!
  s1.attack("target1");

  put_line();
  // ClapTrap FT_1 takes 5 points of damage!
  s1.takeDamage(5);

  put_line();
  // ClapTrap FT_1 is repaired for 3 points!
  s1.beRepaired(3);

  put_line();
  // FragTrap FT_1 requests a high five!
  s1.highFiveGuys();

  put_line();
  // (constructor)ClapTrap Copy constructor called
  // ClapTrap Copy assignment operator called
  // (constructor)FragTrap Copy constructor called
  // FragTrap Copy assignment operator called
  // ClapTrap Copy assignment operator called
  FragTrap s1_copy(s1);

  put_line();
  // FragTrap FT_1 requests a high five!
  s1_copy.highFiveGuys();

  put_line();
  // (constructor)ClapTrap Default constructor called
  // (constructor)FragTrap Default constructor called
  FragTrap s1_assigned;

  put_line();
  // FragTrap Copy assignment operator called
  // ClapTrap Copy assignment operator called
  s1_assigned = s1;

  put_line();
  // FragTrap FT_1 requests a high five!
  s1_assigned.highFiveGuys();

  put_line();
  // (destructor)FragTrap FT_1 has been destroyed!
  // (destructor)ClapTrap FT_1 has been destroyed!
  // (destructor)FragTrap FT_1 has been destroyed!
  // (destructor)ClapTrap FT_1 has been destroyed!
  // (destructor)FragTrap FT_1 has been destroyed!
  // (destructor)ClapTrap FT_1 has been destroyed!
  return 0;
}

#ifdef DEBUG

__attribute__((destructor)) static void destructor() {
  system("leaks -q a.out");
}

#endif
