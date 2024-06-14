/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:06:02 by toshota           #+#    #+#             */
/*   Updated: 2024/06/14 16:02:31 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

#define DEFAULT_HIT_POINTS 100
#define DEFAULT_ENEGY_POINTS 50
#define DEFAULT_ATTACK_DAMAGE 20

ScavTrap::ScavTrap() : ClapTrap() {
  m_hit_points = DEFAULT_HIT_POINTS;
  m_enegy_points = DEFAULT_ENEGY_POINTS;
  m_attack_damage = DEFAULT_ATTACK_DAMAGE;
  std::cout << "(constructor)ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
  m_hit_points = DEFAULT_HIT_POINTS;
  m_enegy_points = DEFAULT_ENEGY_POINTS;
  m_attack_damage = DEFAULT_ATTACK_DAMAGE;
  std::cout << "(constructor)ScavTrap " << m_name << " has been created!"
            << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
  std::cout << "(constructor)ScavTrap Copy constructor called" << std::endl;
  *this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
  std::cout << "ScavTrap Copy assignment operator called" << std::endl;
  if (this != &other) {
    ClapTrap::operator=(other);
  }
  return *this;
}

ScavTrap::~ScavTrap() {
  std::cout << "(destructor)ScavTrap " << m_name << " has been destroyed!"
            << std::endl;
}

void ScavTrap::attack(const std::string& target) {
  if (ClapTrap::can_move() == false) return;
  m_enegy_points--;
  std::cout << "ScavTrap " << m_name << " attacks " << target << ", causing "
            << m_attack_damage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() {
  std::cout << "ScavTrap " << m_name << " is now in Gate keeper mode!"
            << std::endl;
}
