import { Link } from "expo-router";
import React from "react";
import { Text, View } from "react-native";
import { useSafeAreaInsets } from "react-native-safe-area-context";

export default function Page() {
  
  
  return (
    <View className="flex flex-1 items-center justify-center w-full h-full">
        <Text className="flex text-md">Hello World!</Text>
        <Link
            className="text-md font-medium hover:underline web:underline-offset-4"
            href="/"
        >
            Back
        </Link>
    </View>
  );
}
