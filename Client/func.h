#pragma once

template <typename T>
void Safe_Delete_Vector(T& _ref)
{
	for (size_t i = 0; i < _ref.size(); ++i)
	{
		if (_ref[i] != nullptr)
		{
			delete _ref[i];
			_ref[i] = nullptr;
		}
	}
}