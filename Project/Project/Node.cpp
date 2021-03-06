#include "Node.h"

#include <iostream>

Node::Node()
{
	this->penalty = 0;
	this->noFaults = 0;
}

void Node::setAnswers(std::vector<std::pair<int, int>> answer)
{
	this->answers = answer;
}

void Node::addAnswer(std::pair<int, int> answer)
{
	this->answers.push_back(answer);
}

void Node::setAnswer(int index, int fst, int snd)
{
	std::pair<int, int> pair;
	pair.first = fst;
	pair.second = snd;
	this->answers.at(index) = pair;
}

std::vector<std::pair<int, int>> Node::getAnswers() 
{
	return this->answers;
}

std::pair<int, int> Node::getAnswer(int index) const
{
	return this->answers.at(index);
}

unsigned int Node::getAnswersSize() const
{
	return this->answers.size();
}

bool Node::isRoomFree(std::pair<int, int> slot)
{
	for (size_t i = 0; i < this->answers.size(); i++)
	{
		std::pair<int, int> answer = this->answers.at(i);
		if (answer == slot)
			return false;
	}
	return true;
}

void Node::setPenalty(int penalty)
{
	this->penalty = penalty;
	this->updateValue();
}

void Node::setNoFaults(int noFaults)
{
	this->noFaults = noFaults;
	this->updateValue();
}

void Node::incPenalty(int inc)
{
	this->penalty += inc;
	this->updateValue();
}

void Node::incNoFaults(int inc)
{
	this->noFaults += inc;
	this->updateValue();
}

int Node::getPenalty() const
{
	return this->penalty;
}

int Node::getNoFaults() const
{
	return this->noFaults;
}

int Node::getValue() const
{
	return this->value;
}


void Node::print()
{
	for (size_t i = 0; i < this->answers.size(); i++)
	{
		std::pair<int, int> p = this->answers.at(i);
		std::cout << p.first << ", " << p.second << std::endl;
	}
}

void Node::updateValue()
{
	this->value = this->noFaults * 1000 + this->penalty;
}

bool operator==(const Node& lhs, const Node& rhs)
{
	if (lhs.getAnswersSize() == rhs.getAnswersSize()) {
		for (size_t i = 0; i < lhs.getAnswersSize(); i++)
		{
			std::pair<int, int> p1 = lhs.getAnswer(i);
			std::pair<int, int> p2 = rhs.getAnswer(i);

			bool compare = p1.first == p2.first && p1.second == p2.second;
			if (!compare)
				return false;
		}
		return true;
	}
	return false;
}

bool operator!=(const Node& lhs, const Node& rhs)
{
	return !(lhs == rhs);
}

bool operator<(const Node& lhs, const Node& rhs)
{
	if (lhs.getNoFaults() == rhs.getNoFaults())
		return lhs.getPenalty() < rhs.getPenalty();
	else
		return lhs.getNoFaults() < rhs.getNoFaults();
}

bool operator>(const Node& lhs, const Node& rhs)
{
	return rhs < lhs;
}

bool operator<=(const Node& lhs, const Node& rhs)
{
	return !(lhs > rhs);
}


