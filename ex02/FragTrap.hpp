/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:03:48 by toshota           #+#    #+#             */
/*   Updated: 2024/06/14 18:43:49 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
 private:
  /* data */
 public:
  FragTrap();  //  デフォルトコンストラクタ
  FragTrap(const std::string& name);
  FragTrap(const FragTrap& other);  //  コピーコンストラクタ
  FragTrap& operator=(const FragTrap& other);  //  コピー代入演算子
  ~FragTrap();                                 //  デストラクタ

  void highFiveGuys(void);
};
