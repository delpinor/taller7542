class GeneralPantalla
{
    private:
        static GeneralPantalla* instance;
        int static _ancho;
        int static _alto;

        /* Private constructor to prevent instancing. */
        GeneralPantalla();

    public:
        /* Static access method. */
        static GeneralPantalla* GetInstancia();
        static void SetResolucion(int ancho, int alto);
        static int GetAlto();
        static int GetAncho();
};
