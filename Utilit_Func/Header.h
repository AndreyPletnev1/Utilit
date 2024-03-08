#pragma once
struct Card {
    int Suit;
    int Value;
};
Card Deck[36];
Card Hand[36];
Card Choice;
void DeckShuffle(int size);
void DeckGeneration();
void sortDeck(int& size);
void FillHand(int& size);
Card getCardFromMas(int& size, int index);
Card CardFromTheEnd(int& size);
void ReturnAllCardsByNominal(int& size);
int searchRequestedCard(int& size);