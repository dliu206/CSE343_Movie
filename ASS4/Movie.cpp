//
// Created by david on 3/2/2020.
//

#include "Movie.h"

//bool Movie::insert(MovieNode& M) {
//    if (this->Data == nullptr) {
//        this->Data = new MovieNode(M.title, M.year, M.stock);
//    } else if (this->director != M.director) {
//        return false;
//    } else {
//        MovieNode* current = this->Data;
//        while (current != nullptr) {
//            if (*current == M) {
//                current->stock += M.stock;
//                return true;
//            }
//        }
//        this->totalStock +=
//        Movie* temp = new Movie(M.director, M.title, M.year, M.stock);
//    }
//    return false;
//}
//
//void Movie::display() {
//
//}
//
//bool Movie::operator==(const Movie &M) const {
//    return this->director == M.director && this->title == M.title && this->year == M.year;
//}
//
//bool Movie::operator!=(const Movie &M) const {
//    return !(*this == M);
//}
//
//bool Movie::operator<(const Movie &M) const {
//
//}
//
//bool Movie::operator<=(const Movie &M) const {
//
//}
//
//bool Movie::operator>(const Movie &M) const {
//
//}
//
//bool Movie::operator>=(const Movie &M) const {
//
//}