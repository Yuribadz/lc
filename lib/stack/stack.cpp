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
#include "stack.hpp"

Stack::Stack(std::size_t size)
    : max_size_(size <= MAX_CAPACITY ? size : MAX_CAPACITY),
      top_index_(0) {}

bool Stack::push(const std::any &item) {
    if (isFull()) {
        return false;
    }
    data_[top_index_++] = item;
    return true;
}

std::optional<std::any> Stack::pop() {
    if (isEmpty()) {
        return std::nullopt;
    }
    return data_[--top_index_];;
}

std::optional<std::any> Stack::top() const {
    if (isEmpty()) {
        return std::nullopt;
    }
    return data_[top_index_ - 1];
}

bool Stack::isEmpty() const {
    return top_index_ == 0;
}

bool Stack::isFull() const {
    return top_index_ == static_cast<int>(max_size_);
}

std::size_t Stack::size() const {
    return static_cast<std::size_t>(top_index_);
}