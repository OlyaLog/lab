#pragma once
#include "PlayField.h"

class TreeNode
{
public:
	struct Result
	{
		int noughtWinCount;
		int crossWinCount;
		int drawCount;

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
	void setResult(Result newResult);
	Result getResult() const { return result; }

private:
	TreeNode* parent;
	const PlayField field;
	int childQty() const;
	std::vector<TreeNode*> children;
	Result result = { 0,0,0 };
};

