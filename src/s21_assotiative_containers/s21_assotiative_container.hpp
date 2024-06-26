template <typename Key, typename Value>
class AssociativeContainer {
public:
    virtual void insert(const Key& key, const Value& value) = 0;
    virtual void erase(const Key& key) = 0;
    virtual Value* find(const Key& key) = 0;
    virtual ~AssociativeContainer() = default;
};
