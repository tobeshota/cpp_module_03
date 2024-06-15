/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobeshota <tobeshota@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:03:48 by toshota           #+#    #+#             */
/*   Updated: 2024/06/15 12:09:20 by tobeshota        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
 private:
  /* data */
 public:
  ScavTrap();  //  デフォルトコンストラクタ
  ScavTrap(const std::string& name);
  ScavTrap(const ScavTrap& other);  //  コピーコンストラクタ
  ScavTrap& operator=(const ScavTrap& other);  //  コピー代入演算子
  ~ScavTrap();                                 //  デストラクタ

  void attack(const std::string& target);
  void guardGate();
};
