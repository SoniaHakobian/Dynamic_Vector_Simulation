 #ifndef Vector_h
 #define Vector_h

template<typename T>
class DynamicVector
{
    private:
        T* data;
        int size;
        int capacity;

    public:
        DynamicVector();
        DynamicVector(const DynamicVector<T>& vec);
        DynamicVector<T>& operator= (const DynamicVector<T>& vec);
        T& operator[](const unsigned int index) const;
        ~DynamicVector();

        void push_back(const T& element);
        T getElement(const int index);
        int getSize() const;
        static void copyElements(const T* const from,  T* const to, const T count);
        bool isReallocationNecessary() const;
        void reallocateMemory();
        void appendInMemory(const int element);
};


#endif
