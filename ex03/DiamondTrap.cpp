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
  /** DiamondTrapクラスの各属性に任意の値を代入するためには．直接値を代入する必要がある（DiamondTrap::m_attack_damage = FragTrap::m_attack_damageによる代入手法は，代入演算子の両辺ともに同じ値を指しているため，できない）．
   * `class DiamondTrap : public FragTrap, public ScavTrap`(DiamondTrap.hpp, l.19)より，DiamondTrapはFragTrapを継承したのちにScavTrapを継承する．
   * そして，属性m_hit_points，m_enegy_points，m_attack_damageはClapTrapクラスにのみ存在する．
   * このため，各属性には最後に継承されたScavTrapで代入された値が格納されている．
   * また，このことはどのクラスの属性を呼び出すかに関係ない（ClapTrap::m_hit_points == FragTrap::m_hit_points == ScavTrap::m_hit_points == DiamondTrap::m_hit_points == ScavTrapのコンストラクタでm_hit_pointsに代入された値)．
   * したがって，当該クラス（ここではDiamondTrapクラス）の各属性に任意の値を代入するためには，そのクラスのコンストラクタで任意の値を直接代入する(例：`this->m_hit_points = DEFAULT_HIT_POINTS;`)必要がある．
   */
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
