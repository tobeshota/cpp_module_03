/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobeshota <tobeshota@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 11:12:35 by tobeshota         #+#    #+#             */
/*   Updated: 2024/06/15 11:15:46 by tobeshota        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
private:
	std::string m_name;
public:
  DiamondTrap();  //  デフォルトコンストラクタ
  DiamondTrap(const std::string& name);
  DiamondTrap(const DiamondTrap& other);  //  コピーコンストラクタ
  DiamondTrap& operator=(const DiamondTrap& other);  //  コピー代入演算子
  ~DiamondTrap();                                 //  デストラクタ

  void attack(const std::string &target);
  void whoAmI(void);
};

#endif
