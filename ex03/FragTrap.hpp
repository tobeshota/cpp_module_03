/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobeshota <tobeshota@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:03:48 by toshota           #+#    #+#             */
/*   Updated: 2024/06/15 12:09:11 by tobeshota        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
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
