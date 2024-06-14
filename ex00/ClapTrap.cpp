/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobeshota <tobeshota@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:12:20 by tobeshota         #+#    #+#             */
/*   Updated: 2024/06/14 12:05:31 by tobeshota        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#define DEFAULT_HIT_POINTS 10
#define DEFAULT_ENEGY_POINTS 10
#define DEFAULT_ATTACK_DAMAGE 0

ClapTrap::ClapTrap() { std::cout << "(constructor)Default constructor called" << std::endl; }

ClapTrap::ClapTrap(const std::string &name) : m_name(name), m_hit_points(DEFAULT_HIT_POINTS), m_enegy_points(DEFAULT_ENEGY_POINTS), m_attack_damage(DEFAULT_ATTACK_DAMAGE)
{
	std::cout << "(constructor)ClapTrap" << m_name << " has been created!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "(constructor)Copy constructor called" << std::endl;
	*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		m_name = other.get_name();
		m_hit_points = other.get_hit_points();
		m_enegy_points = other.get_enegy_points();
		m_attack_damage = other.get_attack_damage();
	}
	return *this;
}

ClapTrap::~ClapTrap() { std::cout << "(destructor)ClapTrap" << m_name << " has been destroyed!" << std::endl; }

std::string ClapTrap::get_name(void) const
{
	return m_name;
}

int ClapTrap::get_hit_points(void) const
{
	return m_hit_points;
}

int ClapTrap::get_enegy_points(void) const
{
	return m_enegy_points;
}

int ClapTrap::get_attack_damage(void) const
{
	return m_attack_damage;
}

bool ClapTrap::can_move(void) const
{
	if (m_hit_points <= 0)
	{
		std::cout << "ClapTrap" << m_name << "has no hit points left!" << std::endl;
		return false;
	}
	else if (m_enegy_points <= 0)
	{
		std::cout << "ClapTrap" << m_name << "has no enegy points left!" << std::endl;
		return false;
	}
	return true;
}

void ClapTrap::attack(const std::string &target)
{
	if (can_move() == false)
		return ;
	m_enegy_points--;
	std::cout << "ClapTrap" << m_name << " attacks " << target << ", causing" << m_attack_damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	m_hit_points -= amount;
	if (m_hit_points < 0)
		m_hit_points = 0;
	std::cout << "ClapTrap " << m_name << " takes " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (can_move() == false)
		return ;
	m_enegy_points--;
	m_hit_points += amount;
	std::cout << "ClapTrap " << m_name << " is repaired for " << amount << " points!" << std::endl;
}