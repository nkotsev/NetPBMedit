template <class T>
inline int GetNumberOfDigits(T i)
{
  return i > 0 ? (int)log10((double)i) + 1 : 1;
}