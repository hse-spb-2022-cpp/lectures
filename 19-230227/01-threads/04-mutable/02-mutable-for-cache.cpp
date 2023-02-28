struct matrix {
    int determinant() const {
    }

private:
    int n;
    std::vector<int> data;
    mutable std::optional<int> last_determinant;
};
