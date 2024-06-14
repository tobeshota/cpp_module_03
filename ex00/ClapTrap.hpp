/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:10:07 by tobeshota         #+#    #+#             */
/*   Updated: 2024/06/14 15:27:39 by toshota          ###   ########.fr       */
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

  void attack(const std::string& target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
};

#endif
