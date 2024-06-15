/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:06:02 by toshota           #+#    #+#             */
/*   Updated: 2024/06/14 16:02:31 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

#define DEFAULT_HIT_POINTS 100
#define DEFAULT_ENEGY_POINTS 50
#define DEFAULT_ATTACK_DAMAGE 30

DiamondTrap::DiamondTrap() : ClapTrap() {
  this->m_hit_points = DEFAULT_HIT_POINTS;
  this->m_enegy_points = DEFAULT_ENEGY_POINTS;
  this->m_attack_damage = DEFAULT_ATTACK_DAMAGE;
  std::cout << "(constructor)DiamondTrap Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"), m_name(name) {
  this->m_hit_points = DEFAULT_HIT_POINTS;
  this->m_enegy_points = DEFAULT_ENEGY_POINTS;
  this->m_attack_damage = DEFAULT_ATTACK_DAMAGE;
  std::cout << "(constructor)DiamondTrap " << m_name << " has been created!"
            << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other) {
  std::cout << "(constructor)DiamondTrap Copy constructor called" << std::endl;
  *this = other;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
  std::cout << "DiamondTrap Copy assignment operator called" << std::endl;
  if (this != &other) {
    ClapTrap::operator=(other);
  }
  return *this;
}

DiamondTrap::~DiamondTrap() {
  std::cout << "(destructor)DiamondTrap " << m_name << " has been destroyed!"
            << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
  ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
  std::cout << "I am " << m_name << " and my ClapTrap name is " << ClapTrap::m_name << std::endl;
}
