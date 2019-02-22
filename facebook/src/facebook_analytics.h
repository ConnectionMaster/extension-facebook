#ifndef H_FACEBOOK_ANALYTICS
#define H_FACEBOOK_ANALYTICS

extern "C"
{
    #include <lua/lua.h>
    #include <lua/lauxlib.h>
}

namespace dmFacebook {

    namespace Analytics {

        /**
         * \brief The maximum number of parameters that can be sent with an
         * event to Facebook Analytics.
         *
         * \see https://developers.facebook.com/docs/app-events
         */
        const unsigned int MAX_PARAMS = 25;

        /**
         * \brief The internal representation of the predefined events for
         * Facebook Analytics.
         *
         * \note This list has to match the list in facebook_analytics.cpp
         */
        enum Event {
            ACHIEVED_LEVEL          = 0,
            ACTIVATED_APP           = 1,
            ADDED_PAYMENT_INFO      = 2,
            ADDED_TO_CART           = 3,
            ADDED_TO_WISHLIST       = 4,
            COMPLETED_REGISTRATION  = 5,
            COMPLETED_TUTORIAL      = 6,
            DEACTIVATED_APP         = 7,
            INITIATED_CHECKOUT      = 8,
            PURCHASED               = 9,
            RATED                   = 10,
            SEARCHED                = 11,
            SESSION_INTERRUPTIONS   = 12,
            SPENT_CREDITS           = 13,
            TIME_BETWEEN_SESSIONS   = 14,
            UNLOCKED_ACHIEVEMENT    = 15,
            VIEWED_CONTENT          = 16,
            MAX_NUM_EVENTS          = 17
        };

        /**
         * \brief The internal representation of the predefined parameters for
         * Facebook Analytics.
         *
         * \note This list has to match the list in facebook_analytics.cpp.
         */
         enum Parameter {
            CONTENT_ID              = 0,
            CONTENT_TYPE            = 1,
            CURRENCY                = 2,
            DESCRIPTION             = 3,
            LEVEL                   = 4,
            MAX_RATING_VALUE        = 5,
            NUM_ITEMS               = 6,
            PAYMENT_INFO_AVAILABLE  = 7,
            REGISTRATION_METHOD     = 8,
            SEARCH_STRING           = 9,
            SOURCE_APPLICATION      = 10,
            SUCCESS                 = 11,
            MAX_NUM_PARAMS          = 12
         };

        /**
         * \brief Get the event identifier (Facebook SDK string or custom)
         * based on the argument on the Lua stack provided specified by index.
         *
         * \param L The Lua stack.
         * \param index The position on the stack where the event can be found.
         *
         * \exception If the event is neither represented as a string or a
         * number an argerror will be thrown. If the event is represented as a
         * number that doesn't exist an argerror will be thrown. If the event
         * is represented as a string that is empty an argerror will be thrown.
         *
         * \return An event identifier to be used with Facebook Analytics.
         */
        const char* GetEvent(lua_State* L, int index);

        /**
         * \brief Get the parameter identifier (Facebook SDK string or custom)
         * based on the argument on the Lua stack provided specified by index.
         *
         * \param L The Lua stack.
         * \param index The position on the stack where the parameter can be
         * found.
         * \param tableIndex The absolute position on the stack where the table
         * that contains all parameters are stored.
         *
         * \exception If the parameter is neither represented as a string or a
         * number an argerror will be thrown. If the event is represented as a
         * number that doesn't exist an argerror will be thrown. If the event
         * is represented as a string that is empty an argerror will be thrown.
         *
         * \return A parameter identifier to be used with Facebook Analytics.
         */
        const char* GetParameter(lua_State* L, int index, int tableIndex);

        /**
         * \brief Get the values from a table on the Lua stack at the position
         * specified by index and populate the arrays keys and values with the
         * table content.
         *
         * \param L The Lua stack.
         * \param index The position on the stack where the table can be found.
         * \param keys An array that should be populated with keys from the
         * table.
         * \param values An array that should be populated with the values from
         * the table.
         * \param length The length of the arrays keys and values. This
         * parameter will be populated with the number of items that were put
         * into the arrays keys and values.
         */
        void GetParameterTable(lua_State* L, int index, const char** keys,
            const char** values, unsigned int* length);

        /**
         * \brief Push constants for predefined events and predefined paramters
         * onto the stack L.
         *
         * \param L The Lua stack.
         */
        void RegisterConstants(lua_State* L);

    };

};

#endif