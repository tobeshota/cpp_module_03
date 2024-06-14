/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:19:58 by tobeshota         #+#    #+#             */
/*   Updated: 2024/06/14 19:23:01 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
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
  ScavTrap *st = new ScavTrap("st");
  free_instance(st);
  put_line();
}
*/

int main() {
  put_line();
  // (constructor)ClapTrap ST_1 has been created!
  // (constructor)ScavTrap ST_1 has been created!
  ScavTrap s1("ST_1");

  put_line();
  // ScavTrap ST_1 attacks target1, causing 20 points of damage!
  s1.attack("target1");

  put_line();
  // ClapTrap ST_1 takes 5 points of damage!
  s1.takeDamage(5);

  put_line();
  // ClapTrap ST_1 is repaired for 3 points!
  s1.beRepaired(3);

  put_line();
  // ScavTrap ST_1 is now in Gate keeper mode!
  s1.guardGate();

  put_line();
  // (constructor)ClapTrap Copy constructor called
  // ClapTrap Copy assignment operator called
  // (constructor)ScavTrap Copy constructor called
  // ScavTrap Copy assignment operator called
  // ClapTrap Copy assignment operator called
  ScavTrap s1_copy(s1);

  put_line();
  // ScavTrap ST_1 is now in Gate keeper mode!
  s1_copy.guardGate();

  put_line();
  // (constructor)ClapTrap Default constructor called
  // (constructor)ScavTrap Default constructor called
  ScavTrap s1_assigned;

  put_line();
  // ScavTrap Copy assignment operator called
  // ClapTrap Copy assignment operator called
  s1_assigned = s1;

  put_line();
  // ScavTrap ST_1 is now in Gate keeper mode!
  s1_assigned.guardGate();

  put_line();
  // (destructor)ScavTrap ST_1 has been destroyed!
  // (destructor)ClapTrap ST_1 has been destroyed!
  // (destructor)ScavTrap ST_1 has been destroyed!
  // (destructor)ClapTrap ST_1 has been destroyed!
  // (destructor)ScavTrap ST_1 has been destroyed!
  // (destructor)ClapTrap ST_1 has been destroyed!
  return 0;
}

#ifdef DEBUG

__attribute__((destructor)) static void destructor() {
  system("leaks -q a.out");
}

#endif
