#pragma once

template <typename T>
void Safe_Delete_Vector(T& _ref)
{
	for (size_t i = 0; i < _ref.size(); ++i)
	{
		if (_ref[i] != nullptr)
		{
			delete _ref[i];
		}
	}
	_ref.clear();
}

template <typename T>
void Safe_Delete_map(T& _ref)
{
	typename T::iterator iter = _ref.begin();

	for (; iter != _ref.end(); ++iter)
	{
		if (iter->second != nullptr)
		{
			delete iter->second;
		}
	}
	_ref.clear();
}