#ifndef TQUEUE_ITEM_H
#define TQUEUE_ITEM_H

#include "square.h"

class TQueueItem {
public:
	TQueueItem(const Square& square);
	TQueueItem(const TQueueItem& other);

	TQueueItem* SetNext(TQueueItem* next);
	TQueueItem* GetNext();

	Square GetSquare();

	friend std::ostream& operator<<(std::ostream& os, const TQueueItem& obj);

	virtual ~TQueueItem();

private:
	Square square;
	TQueueItem* next;
};

#endif // TQUEUE_ITEM_H

