import { Link } from "expo-router";
import React from "react";
import { Text, View } from "react-native";
import { useSafeAreaInsets } from "react-native-safe-area-context";
import { Pressable } from "react-native";
import { useRouter } from "expo-router";


export default function Page() {

  return (
    
    <View className="flex flex-1 bg-background justify-center items-center">
      {/* <Header /> */}
      <Content />
      <Footer />
    </View>
  );
}

function Content() {


  const router = useRouter();
  return (
    <View className="flex-1">
      <View className="py-12 md:py-24 lg:py-32 xl:py-48">
        <View className="px-4 md:px-6">
          <View className="flex flex-col items-center gap-4 text-center">
            <Text
              role="heading"
              className="text-3xl text-center native:text-5xl font-bold tracking-tighter sm:text-4xl md:text-5xl lg:text-6xl"
            >
            Eco-Grow
            </Text>
            <Text className="mx-auto max-w-[700px] text-l text-center md:text-xl">
              Revolutionizing Agriculture with Smart IoT Solutions for a Sustainable Future
            </Text>

            <View className="gap-4 flex flex-col items-center py-24">
            <Pressable onPress={() => temp(router)} className="flex items-center justify-center bg-primary rounded-lg font-medium">
              <View className="flex h-9 items-center justify-center overflow-hidden rounded-md px-4 py-2 text-sm text-white font-medium">
                <Text className="text-background">Explore</Text>
              </View>
            </Pressable>
            </View>
          </View>
        </View>
      </View>
    </View>
  );
}

// Temporary function to test routing
// Will be removed in the final version
function temp(router){
  router.push("about");
  console.log("clicked");
}

function Header() {
  const { top } = useSafeAreaInsets();
  return (
    <View style={{ paddingTop: top }}>
      <View className="px-4 lg:px-6 h-14 flex items-center flex-row justify-between ">
        <Link className="font-bold flex-1 items-center justify-center" href="/">
          ACME
        </Link>
        <View className="flex flex-row gap-4 sm:gap-6">
          <Link
            className="text-md font-medium hover:underline web:underline-offset-4"
            href="/about"
          >
            About
          </Link>
          <Link
            className="text-md font-medium hover:underline web:underline-offset-4"
            href="/"
          >
            Product
          </Link>
          <Link
            className="text-md font-medium hover:underline web:underline-offset-4"
            href="/"
          >
            Pricing
          </Link>
        </View>
      </View>
    </View>
  );
}

function Footer() {
  const { bottom } = useSafeAreaInsets();
  return (
    <View
      className="flex shrink-0 bg-gray-100 native:hidden"
      style={{ paddingBottom: bottom }}
    >
      <View className="py-6 flex-1 items-start px-4 md:px-6 ">
        <Text className={"text-center text-gray-700"}>
          © {new Date().getFullYear()} Me
        </Text>
      </View>
    </View>
  );
}
