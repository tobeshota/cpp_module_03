/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:19:58 by tobeshota         #+#    #+#             */
/*   Updated: 2024/06/14 15:32:43 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) {
  ClapTrap robot("CT_1");

  robot.attack("target1");
  robot.takeDamage(5);
  robot.beRepaired(3);

  robot.attack("target2");
  robot.takeDamage(15);
  robot.beRepaired(10);
  return 0;
}

#ifdef DEBUG

__attribute__((destructor)) static void destructor() {
  system("leaks -q a.out");
}

#endif
