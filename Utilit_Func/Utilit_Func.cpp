#include <iostream>
struct Card {
    int Suit;
    int Value;
};
Card Deck[36];
Card Hand[36];
Card Choice;
// Перемешивание карт
void DeckShuffle(int size) {
    Card temp0;
    int random;
    for (int i = 0; i < size; i++) {
        random = rand() % size;
        temp0.Value = Deck[i].Value;
        temp0.Suit = Deck[i].Suit;
        Deck[i].Value = Deck[random].Value;
        Deck[i].Suit = Deck[random].Suit;
        Deck[random].Value = temp0.Value;
        Deck[random].Suit = temp0.Suit;
    }
}
//Генерация карт
void DeckGeneration() {
    int i = 0;//Выбор индекса карты
    for (int Suit = 1; Suit <= 4; Suit++) {
        for (int Value = 6; Value <= 14; Value++) {
            Deck[i].Suit = Suit;
            Deck[i].Value = Value;
            i++;
        }
    }
}
    //сортирует карты в руке по номиналу
void sortDeck(int& size)
{
    for (int i = 0; i < size - 1; i++)
    {
        Card temp0;
        if (Hand[i].Value > Hand[i + 1].Value and Hand[i].Value != 0)
        {
            temp0.Value = Hand[i].Value;
            temp0.Suit = Hand[i].Suit;
            Hand[i].Value = Hand[i + 1].Value;
            Hand[i].Suit = Hand[i + 1].Suit;
        }
    }
}
//добавляет карту в конец массива руки
void FillHand(int& size)
{
	Hand[size - 1].Value = Choice.Value;
	Hand[size - 1].Suit = Choice.Suit;
}
Card getCardFromMas(Card mas[], int& size, int index)
{
    Choice = mas[index]; // Сохраняем карту для возврата
    // Сдвигаем все элементы справа на позицию влево
    for (int i = index; i < size - 1; i++) mas[i] = mas[i + 1];
    // Уменьшаем размер массива
    size--;
    return Choice; // Возвращаем удаленную карту
}
Card CardFromTheEnd(int& size)
{
	Card temp0= Hand[size - 1];
    size--;
	return temp0;
}
void ReturnAllCardsByValue(int& size) 
{
    int count = 0; // Счетчик найденных карт с заданным номиналом
    // Ищем и удаляем все карты с заданным номиналом из руки
    for (int i = 0; i < size; i++) 
    {
        if (Hand[i].Value == Choice.Value) {
            // Вызываем столько раз, сколько найдено карт
            getCardFromMas(Hand,size, i);
            count++;
            i--; //Изменяем индекс после удаления элемента
        }
    }
}
int searchRequestedCard(int& size)
{
    for (int i = 0; i < size; i++)
    {
        if (Hand[i].Value == Choice.Value)
            return i;
        else
            return -1;
    }
}
void CardDistriburion(int& size,int& handSize, int n)
{
    for (int i = 0; i < n; i++)
    {
        Deck[i].Value = Hand[i].Value;
		Deck[i].Suit = Hand[i].Suit;
        size--;
		handSize++;
    }
}