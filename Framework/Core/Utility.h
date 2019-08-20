//=====================================
//
//���[�e�B���e�B�w�b�_[Utility.h]
//Author:GP12B332 21 ���ԗY��
//
//=====================================
#ifndef _UTILITY_H_
#define _UTILITY_H_

/**************************************
�O���錾
***************************************/

/**************************************
�}�N���E�񋓎q��`
***************************************/

/**************************************
�N���X��`
***************************************/
class Utility
{
public:
	/**************************************
	�N���X��`
	***************************************/
	template <class T>
	static void DeleteContainer(T& container)
	{
		for (auto&& p : container)
		{
			delete p;
			p = NULL;
		}
		container.clear();
	}

	/**************************************
	�N���X��`
	***************************************/
	template <class T>
	static void DeleteMap(T& map)
	{
		for (auto&& pair : map)
		{
			delete pair.second;
			pair.second = NULL;
		}
		map.clear();
	}

private:
	Utility();
};

#endif