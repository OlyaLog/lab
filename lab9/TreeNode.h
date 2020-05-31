#pragma once
#include "PlayField.h"

class TreeNode
{
public:
	struct Result
	{
		int noughtWinCount = 0;
		int crossWinCount = 0;
		int drawCount = 0;

		Result& operator+=(const Result& ir)
		{
			noughtWinCount += ir.noughtWinCount;
			crossWinCount += ir.crossWinCount;
			drawCount += ir.drawCount;
			return *this;
		}
	};
	TreeNode(PlayField newField = PlayField(), TreeNode* newTreeNode = nullptr);
	~TreeNode();
	bool isTerminal() const;
	void addChild(TreeNode*);
	TreeNode& operator[] (int) const;
	int childCount() const;
	const PlayField& value() const;
	void addResult(Result newResult);
	Result result;

private:
	TreeNode* parent;
	const PlayField field;
	int childQty() const;
	std::vector<TreeNode*> children;
};

