/* Copyright 2023 Yuriy Badziuk
 * This file is part of the program and is made available under
 * the terms of the GNU General Public License version 3 as published by the
 * Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#ifndef STACK_H
#define STACK_H

#include <any>
#include <array>
#include <optional>


class Stack {
public:
    explicit Stack(std::size_t size);
    bool push(const std::any &item);
    std::optional<std::any> pop();
    std::optional<std::any> top() const;
    bool isEmpty() const;
    bool isFull() const;
    std::size_t size() const;

private:
    static constexpr std::size_t MAX_CAPACITY = 100;
    std::array<std::any, MAX_CAPACITY> data_;
    std::size_t max_size_;
    int top_index_;
};

#endif // STACK_HPP
