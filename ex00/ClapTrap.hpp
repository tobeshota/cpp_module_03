/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobeshota <tobeshota@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:10:07 by tobeshota         #+#    #+#             */
/*   Updated: 2024/06/14 12:03:53 by tobeshota        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
 private:
  std::string m_name;
  int m_hit_points;
  int m_enegy_points;
  int m_attack_damage;
  bool can_move(void) const;

 public:
  ClapTrap();                                  //  デフォルトコンストラクタ
  ClapTrap(const std::string& name);
  ClapTrap(const ClapTrap& other);             //  コピーコンストラクタ
  ClapTrap& operator=(const ClapTrap& other);  //  コピー代入演算子
  ~ClapTrap();                                 //  デストラクタ

  std::string get_name(void) const;
  int get_hit_points(void) const;
  int get_enegy_points(void) const;
  int get_attack_damage(void) const;

  void attack(const std::string& target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
};

#endif
