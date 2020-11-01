/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constant.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 12:42:20 by nhamill           #+#    #+#             */
/*   Updated: 2020/10/31 12:42:20 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_CONSTANT_H
# define LS_CONSTANT_H

# define FLAGS "l1mAadRfrStcuUTFpnogiksh"

enum	e_position_flag_bits {
	FLAG_LWR_L, FLAG_ONE, FLAG_LWR_M, FLAG_UPR_A, FLAG_LWR_A, FLAG_LWR_D,
	FLAG_UPR_R, FLAG_LWR_F, FLAG_LWR_R, FLAG_UPR_S, FLAG_LWR_T, FLAG_LWR_C,
	FLAG_LWR_U, FLAG_UPR_U, FLAG_UPR_T, FLAG_UPR_F, FLAG_LWR_P, FLAG_LWR_N,
	FLAG_LWR_O, FLAG_LWR_G, FLAG_LWR_I, FLAG_LWR_K, FLAG_LWR_S, FLAG_LWR_H
};

# define FAIL 0x80000000

# define LWR_A (1 << FLAG_LWR_A)
# define UPR_A (1 << FLAG_UPR_A)
# define LWR_C (1 << FLAG_LWR_C)
# define LWR_D (1 << FLAG_LWR_D)
# define LWR_F (1 << FLAG_LWR_F)
# define UPR_F (1 << FLAG_UPR_F)
# define LWR_G (1 << FLAG_LWR_G)
# define LWR_H (1 << FLAG_LWR_H)
# define LWR_I (1 << FLAG_LWR_I)
# define LWR_K (1 << FLAG_LWR_K)
# define LWR_L (1 << FLAG_LWR_L)
# define LWR_M (1 << FLAG_LWR_M)
# define LWR_N (1 << FLAG_LWR_N)
# define LWR_O (1 << FLAG_LWR_O)
# define LWR_P (1 << FLAG_LWR_P)
# define LWR_R (1 << FLAG_LWR_R)
# define UPR_R (1 << FLAG_UPR_R)
# define LWR_S (1 << FLAG_LWR_S)
# define UPR_S (1 << FLAG_UPR_S)
# define LWR_T (1 << FLAG_LWR_T)
# define UPR_T (1 << FLAG_UPR_T)
# define UPR_U (1 << FLAG_UPR_U)
# define LWR_U (1 << FLAG_LWR_U)
# define ONE (1 << FLAG_ONE)

# define DEFAULT (ONE | LWR_C | LWR_F)

# define SORT (LWR_F | UPR_S | LWR_T)
# define NULL_SORT (~SORT)
# define TIME (LWR_C | LWR_U | UPR_U)
# define NULL_TIME (~TIME)
# define LONG_LIST (LWR_L | LWR_G | LWR_N | LWR_O)
# define FRMT_OUT (LWR_M | LWR_L | ONE)
# define NULL_FRMT_OUT ~(FRMT_OUT)

# define ERR_FLAG_FAIL "Wrong flag here"
# define ERR_HELP "Use help"
# define MGS_HELP "Help"

# define SEP_STD "\n"
# define SEP_M ","
# define SEP_BLANK " "
# define SEP_PATH '/'

# define START_HEAP_SIZE 1
# define COEF_HEAP_INC 2

# define MINOR_PROBLEMS 1
# define SERIOUS_TROUBLE 2

#endif
