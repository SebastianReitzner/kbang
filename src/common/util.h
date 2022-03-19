/***************************************************************************
 *   Copyright (C) 2008 by MacJariel                                       *
 *   echo "badmailet@gbalt.dob" | tr "edibmlt" "ecrmjil"                   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <random>
#include <vector>


#define CALL_MEMBER_FN(object,ptrToMember)  ((object).*(ptrToMember))

std::string randomToken(int minLength, int maxLength);

// TODO: assess necessity
//bool randomBool(qreal probability);

template <typename T>
inline void shuffleList(std::vector<T>& vec)
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(0, vec.size()-1);

    int swapCount = vec.size() * 4;
    while(swapCount-- != 0)
    {
        std::iter_swap(dist(rng), dist(rng));
    }
}

class INonCopyable
{
protected:
    INonCopyable() {}
    ~INonCopyable() {}
private:
    INonCopyable(const INonCopyable&);
    INonCopyable& operator=(const INonCopyable&);
};


#endif
