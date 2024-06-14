/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:06:02 by toshota           #+#    #+#             */
/*   Updated: 2024/06/14 18:46:58 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

#define DEFAULT_HIT_POINTS 100
#define DEFAULT_ENEGY_POINTS 100
#define DEFAULT_ATTACK_DAMAGE 30

FragTrap::FragTrap() : ClapTrap() {
  m_hit_points = DEFAULT_HIT_POINTS;
  m_enegy_points = DEFAULT_ENEGY_POINTS;
  m_attack_damage = DEFAULT_ATTACK_DAMAGE;
  std::cout << "(constructor)FragTrap Default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
  m_hit_points = DEFAULT_HIT_POINTS;
  m_enegy_points = DEFAULT_ENEGY_POINTS;
  m_attack_damage = DEFAULT_ATTACK_DAMAGE;
  std::cout << "(constructor)FragTrap " << m_name << " has been created!"
            << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
  std::cout << "(constructor)FragTrap Copy constructor called" << std::endl;
  *this = other;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
  std::cout << "FragTrap Copy assignment operator called" << std::endl;
  if (this != &other) {
    ClapTrap::operator=(other);
  }
  return *this;
}

FragTrap::~FragTrap() {
  std::cout << "(destructor)FragTrap " << m_name << " has been destroyed!"
            << std::endl;
}

void FragTrap::highFiveGuys(void)
{
	std::cout << "FragTrap " << m_name << " requests a high five!" << std::endl;
}
