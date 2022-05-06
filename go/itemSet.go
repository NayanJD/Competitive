package main

import "sync"

type Item string
type ItemSet struct {
	items map[Item]bool
	m     sync.RWMutex
}

func NewItemSet() ItemSet {
	return ItemSet{items: map[Item]bool{}, m: sync.RWMutex{}}
}

func (s ItemSet) Add(item Item) *ItemSet {

	s.m.Lock()
	defer s.m.Unlock()

	s.items[item] = true

	return &ItemSet{items: s.items}
}

func (s ItemSet) Delete(item Item) bool {
	s.m.Lock()
	defer s.m.Unlock()

	if _, ok := s.items[item]; !ok {
		return false
	}

	delete(s.items, item)

	return true
}

func (s ItemSet) Has(item Item) bool {
	s.m.RLock()
	defer s.m.RUnlock()

	_, ok := s.items[item]

	return ok
}

func (s ItemSet) Size() int {

	s.m.RLock()
	defer s.m.RUnlock()

	return len(s.items)
}

func (s ItemSet) Items() []Item {
	s.m.RLock()
	defer s.m.RUnlock()

	itemSlice := make([]Item, 0)

	for item, _ := range s.items {
		itemSlice = append(itemSlice, item)
	}

	return itemSlice
}

type Sets interface {
	Add(Item) *ItemSet
	Delete(Item) bool
	Has(Item) bool
	Size() int
	Items() []Item
}

func main() {
	// var set Sets

	// set = ItemSet{items: map[Item]bool{}}

}
